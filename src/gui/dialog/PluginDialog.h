/*
 * Xournal++
 *
 * Plugin manage dialog
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "gui/GladeGui.h"

class PluginController;
class PluginDialogEntry;
class Settings;

class PluginDialog : public GladeGui
{
public:
	PluginDialog(GladeSearchpath* gladeSearchPath, Settings* settings);
	~PluginDialog() override;

public:
	void loadPluginList(PluginController* pc);
	void show(GtkWindow* parent) override;

private:
	void saveSettings();

private:
	XOJ_TYPE_ATTRIB;

	Settings* settings;

	vector<PluginDialogEntry*> plugins;
};
