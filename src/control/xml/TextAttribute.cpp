#include "TextAttribute.h"
#include <StringUtils.h>

#include <utility>

TextAttribute::TextAttribute(string name, string value)
 : XMLAttribute(name),
   value(std::move(value))
{
	XOJ_INIT_TYPE(TextAttribute);
}

TextAttribute::~TextAttribute()
{
	XOJ_RELEASE_TYPE(TextAttribute);
}

void TextAttribute::writeOut(OutputStream* out)
{
	XOJ_CHECK_TYPE(TextAttribute);

	string v = this->value;
	StringUtils::replaceAllChars(v, {
		replace_pair('&', "&amp;"),
		replace_pair('\"', "&quot;"),
		replace_pair('<', "&lt;"),
		replace_pair('>', "&gt;"),
	});
	out->write(v);
}
