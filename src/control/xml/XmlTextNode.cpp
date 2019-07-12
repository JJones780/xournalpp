#include "XmlTextNode.h"

#include <StringUtils.h>

XmlTextNode::XmlTextNode(const char* tag, const char* text) : XmlAudioNode(tag)
{
	XOJ_INIT_TYPE(XmlTextNode);

	this->text = g_strdup(text);
}

XmlTextNode::XmlTextNode(const char* tag) : XmlAudioNode(tag)
{
	XOJ_INIT_TYPE(XmlTextNode);

	this->text = nullptr;

	XOJ_RELEASE_TYPE(XmlTextNode);
}

XmlTextNode::~XmlTextNode()
{
	XOJ_CHECK_TYPE(XmlTextNode);

	g_free(this->text);
	this->text = nullptr;

	XOJ_RELEASE_TYPE(XmlTextNode);
}

void XmlTextNode::setText(const char* text)
{
	XOJ_CHECK_TYPE(XmlTextNode);

	g_free(this->text);
	this->text = g_strdup(text);
}

void XmlTextNode::writeOut(OutputStream* out)
{
	XOJ_CHECK_TYPE(XmlTextNode);

	out->write("<");
	out->write(tag);
	writeAttributes(out);

	out->write(">");

	string tmp(this->text);
	StringUtils::replaceAllChars(tmp,{
		replace_pair('&', "&amp;"),
		replace_pair('<', "&lt;"),
		replace_pair('>', "&gt;")
	});
	out->write(tmp);

	out->write("</");
	out->write(tag);
	out->write(">\n");
}
