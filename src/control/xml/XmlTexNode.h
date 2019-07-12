/*
 * Xournal++
 *
 * XML Writer helper class
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "XmlNode.h"

class XmlTexNode : public XmlNode
{
public:
	XmlTexNode(const char* tag, string& binaryData);
	~XmlTexNode() override;

public:
	void writeOut(OutputStream* out) override;

private:
	XOJ_TYPE_ATTRIB;

	/**
	 * Binary .PNG or .PDF
	 */
	string& binaryData;
};
