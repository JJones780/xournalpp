#! /bin/bash

# assumes build dir is called 'build' 
# for clang tidy info see:   https://www.kdab.com/clang-tidy-part-1-modernize-source-code-using-c11c14/


br=`git rev-parse --abbrev-ref HEAD`
failed=0;

if [ "$br" = "master" ]; then
    echo "Do not run on master branch."
    failed=1;
fi
if [ "$br" = "HEAD" ]; then
    echo "GIT: Detached head? Please run on a non-master branch."
    echo $br
    failed=1;
fi

if [ ! -f "./build/compile_commands.json" ]; then 
    echo -e "\n\nERROR: The './build/compile_commands.json' file does not exist\n";
    echo -e "\tAssumes build dir is:  build"
    echo -e "\tCheck: Is this script being run from directory above build?"
    echo -e "\tYou can create compile_commands.json by running:\n\t\t  cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON  build\n\n"
    failed=1;
fi

if [ ! $failed -eq 0 ]; then
    echo "Fix issues and try again.. exiting.";
    exit 1
fi


for m in `clang-tidy-8 --list-checks -checks='*' | grep "modernize"`;
#for m in `echo modernize-use-nullptr`;
do
    echo run-clang-tidy-8 -p ./build -header-filter=".*" -checks="-*,$m" -fix ;
    run-clang-tidy-8 -p ./build -header-filter=".*" -checks="-*,$m" -fix ;
    git add -u;
    git commit --author='AutoModernize<>' -m "clang-tidy: $m"; 
done

