/*
 * Xournal++
 *
 * [Header description]
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once


#include "XmlNode.h"

class XmlAudioNode : public XmlNode
{
public:
	XmlAudioNode(const char* tag);
	~XmlAudioNode() override;

private:
	XmlAudioNode(const XmlAudioNode& node) = delete;
	void operator=(const XmlAudioNode& node) = delete;

public:
	string getAudioFilename();
	void setAudioFilename(string filename);

private:
	XOJ_TYPE_ATTRIB;

	string audioFilename;
};


