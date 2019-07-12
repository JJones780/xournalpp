#include "SelectBackgroundColorDialog.h"

#include "control/Control.h"

#include <Util.h>

#include <config.h>
#include <i18n.h>

#define RGBA_FROM_HEX(value) \
		{.red = ((value >> 16) & 0xFF) / 255.0, .green = ((value >> 8) & 0xFF) / 255.0, .blue = (value & 0xFF) / 255.0, .alpha = 1.0}

GdkRGBA background1[] = {
		RGBA_FROM_HEX(0xfabebe),
		RGBA_FROM_HEX(0xfee7c4),
		RGBA_FROM_HEX(0xfef8c9),
		RGBA_FROM_HEX(0xdcf6c1),
		RGBA_FROM_HEX(0xd4e2f0),
		RGBA_FROM_HEX(0xe6d8e4),
		RGBA_FROM_HEX(0xf8ead3),
		RGBA_FROM_HEX(0xdadcda),
		RGBA_FROM_HEX(0xfafaf9)
};

const int background1Count = sizeof(background1) / sizeof(GdkRGBA);

GdkRGBA backgroundXournal[] = {
		RGBA_FROM_HEX(0xffffff),
		RGBA_FROM_HEX(0xa0e8ff),
		RGBA_FROM_HEX(0x80ffc0),
		RGBA_FROM_HEX(0xffc0d4),
		RGBA_FROM_HEX(0xffc080),
		RGBA_FROM_HEX(0xffff80)
};

const int backgroundXournalCount = sizeof(backgroundXournal) / sizeof(GdkRGBA);

SelectBackgroundColorDialog::SelectBackgroundColorDialog(Control* control)
 : control(control),
   lastBackgroundColors{
	RGBA_FROM_HEX(0xffffff),
	RGBA_FROM_HEX(0xffffff),
	RGBA_FROM_HEX(0xffffff),
	RGBA_FROM_HEX(0xffffff),
	RGBA_FROM_HEX(0xffffff),
	RGBA_FROM_HEX(0xffffff),
	RGBA_FROM_HEX(0xffffff),
	RGBA_FROM_HEX(0xffffff),
	RGBA_FROM_HEX(0xffffff)
   }
{
	XOJ_INIT_TYPE(SelectBackgroundColorDialog);


	Settings* settings = control->getSettings();
	SElement& el = settings->getCustomElement("lastUsedPageBgColor");

	int count = 0;
	el.getInt("count", count);

	int index = 0;

	for (int i = 0; i < count && index < LAST_BACKGROUND_COLOR_COUNT; i++)
	{
		int color = -1;
		char* settingName = g_strdup_printf("color%02i", i);
		bool read = el.getInt(settingName, color);
		g_free(settingName);

		if (!read)
		{
			continue;
		}

		Util::apply_rgb_togdkrgba(lastBackgroundColors[index], color);

		index++;
	}
}

SelectBackgroundColorDialog::~SelectBackgroundColorDialog()
{
	XOJ_CHECK_TYPE(SelectBackgroundColorDialog);
	XOJ_RELEASE_TYPE(SelectBackgroundColorDialog);
}

void SelectBackgroundColorDialog::storeLastUsedValuesInSettings()
{
	XOJ_CHECK_TYPE(SelectBackgroundColorDialog);

	if (this->selected < 0)
	{
		// No color selected, do not save to list
		return;
	}

	GdkRGBA newColor;
	Util::apply_rgb_togdkrgba(newColor, this->selected);

	for (auto & lastBackgroundColor : lastBackgroundColors)
	{
		if (gdk_rgba_equal(&lastBackgroundColor, &newColor))
		{
			// The new color is already in the list, do not save
			return;
		}
	}


	Settings* settings = control->getSettings();
	SElement& el = settings->getCustomElement("lastUsedPageBgColor");

	// Move all colors one step back
	for (int i = LAST_BACKGROUND_COLOR_COUNT- 1; i > 0; i--)
	{
		lastBackgroundColors[i] = lastBackgroundColors[i - 1];
	}

	lastBackgroundColors[0] = newColor;

	el.setInt("count", LAST_BACKGROUND_COLOR_COUNT);
	for (int i = 0; i < LAST_BACKGROUND_COLOR_COUNT; i++)
	{
		char* settingName = g_strdup_printf("color%02i", i);
		el.setIntHex(settingName, Util::gdkrgba_to_hex(lastBackgroundColors[i]));
		g_free(settingName);
	}

	settings->customSettingsChanged();
}

int SelectBackgroundColorDialog::getSelectedColor()
{
	XOJ_CHECK_TYPE(SelectBackgroundColorDialog);

	return this->selected;
}

void SelectBackgroundColorDialog::show(GtkWindow* parent)
{
	XOJ_CHECK_TYPE(SelectBackgroundColorDialog);

	GtkWidget* dialog = gtk_color_chooser_dialog_new(_("Select background color"), parent);
	gtk_color_chooser_set_use_alpha(GTK_COLOR_CHOOSER(dialog), false);

	gtk_color_chooser_add_palette(GTK_COLOR_CHOOSER(dialog), GTK_ORIENTATION_HORIZONTAL, 9,
			background1Count, background1);

	gtk_color_chooser_add_palette(GTK_COLOR_CHOOSER(dialog), GTK_ORIENTATION_HORIZONTAL, 9,
			backgroundXournalCount, backgroundXournal);

	// Last used colors (only by background, the general last used are shared with the
	// pen and highlighter etc.)
	gtk_color_chooser_add_palette(GTK_COLOR_CHOOSER(dialog), GTK_ORIENTATION_HORIZONTAL, 9,
			LAST_BACKGROUND_COLOR_COUNT, lastBackgroundColors);


	int response = gtk_dialog_run(GTK_DIALOG(dialog));
	if (response == GTK_RESPONSE_OK)
	{
		GdkRGBA color;
		gtk_color_chooser_get_rgba(GTK_COLOR_CHOOSER(dialog), &color);
		this->selected = Util::gdkrgba_to_hex(color);

		storeLastUsedValuesInSettings();
	}

	gtk_widget_destroy(dialog);
}
