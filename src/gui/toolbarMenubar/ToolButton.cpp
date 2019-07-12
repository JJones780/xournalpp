#include "ToolButton.h"

#include "gui/widgets/gtkmenutooltogglebutton.h"

ToolButton::ToolButton(ActionHandler* handler, string id, ActionType type, string iconName, string description,
					   GtkWidget* menuitem)
 : AbstractToolItem(id, handler, type, menuitem)
{
	XOJ_INIT_TYPE(ToolButton);

	this->iconName = iconName;
	this->description = description;
}

ToolButton::ToolButton(ActionHandler* handler, string id, ActionType type, ActionGroup group,
					   bool toolToggleOnlyEnable, string iconName, string description,
					   GtkWidget* menuitem)
 : AbstractToolItem(id, handler, type, menuitem)
{
	XOJ_INIT_TYPE(ToolButton);

	this->iconName = iconName;
	this->description = description;
	this->group = group;
	this->toolToggleOnlyEnable = toolToggleOnlyEnable;
}

ToolButton::~ToolButton()
{
	XOJ_RELEASE_TYPE(ToolButton);
}

/**
 * Register a popup menu entry, create a popup menu, if none is there
 *
 * @param name The name of the item
 * @return The created menu item
 */
GtkWidget* ToolButton::registerPopupMenuEntry(string name, string iconName)
{
	XOJ_CHECK_TYPE(ToolButton);

	if (this->popupMenu == nullptr)
	{
		setPopupMenu(gtk_menu_new());
	}

	GtkWidget* menuItem = nullptr;
	if (iconName == "")
	{
		menuItem = gtk_check_menu_item_new_with_label(name.c_str());
	}
	else
	{
		menuItem = gtk_check_menu_item_new();

		GtkWidget* box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
		gtk_container_add(GTK_CONTAINER(box), gtk_image_new_from_icon_name(iconName.c_str(), GTK_ICON_SIZE_SMALL_TOOLBAR));

		GtkWidget* label = gtk_label_new(name.c_str());
		gtk_label_set_xalign(GTK_LABEL(label), 0.0);
		gtk_box_pack_end(GTK_BOX(box), label, true, true, 0);

		gtk_container_add(GTK_CONTAINER(menuItem), box);
	}

	gtk_check_menu_item_set_draw_as_radio(GTK_CHECK_MENU_ITEM(menuItem), true);
	gtk_widget_show_all(menuItem);
	gtk_container_add(GTK_CONTAINER(this->popupMenu), menuItem);

	return menuItem;
}

void ToolButton::updateDescription(string description)
{
	XOJ_CHECK_TYPE(ToolButton);

	this->description = description;
	if (GTK_IS_TOOL_ITEM(item))
	{
		gtk_tool_item_set_tooltip_text(GTK_TOOL_ITEM(item), description.c_str());
		gtk_tool_button_set_label(GTK_TOOL_BUTTON(item), description.c_str());
	}
}

GtkToolItem* ToolButton::newItem()
{
	XOJ_CHECK_TYPE(ToolButton);

	GtkToolItem* it;

	if (group != GROUP_NOGROUP)
	{
		if (popupMenu)
		{
			it = gtk_menu_tool_toggle_button_new(gtk_image_new_from_icon_name(iconName.c_str(), GTK_ICON_SIZE_SMALL_TOOLBAR), description.c_str());
			gtk_menu_tool_toggle_button_set_menu(GTK_MENU_TOOL_TOGGLE_BUTTON(it), popupMenu);
		}
		else
		{
			it = gtk_toggle_tool_button_new();
			gtk_tool_button_set_icon_widget(GTK_TOOL_BUTTON(it), gtk_image_new_from_icon_name(iconName.c_str(), GTK_ICON_SIZE_SMALL_TOOLBAR));
		}
	}
	else
	{
		if (popupMenu)
		{
			it = gtk_menu_tool_button_new(gtk_image_new_from_icon_name(iconName.c_str(), GTK_ICON_SIZE_SMALL_TOOLBAR), description.c_str());
			gtk_menu_tool_button_set_menu(GTK_MENU_TOOL_BUTTON(it), popupMenu);
		}
		else
		{
			it = gtk_tool_button_new(gtk_image_new_from_icon_name(iconName.c_str(), GTK_ICON_SIZE_SMALL_TOOLBAR), description.c_str());
		}
	}
	gtk_tool_item_set_tooltip_text(GTK_TOOL_ITEM(it), description.c_str());
	gtk_tool_button_set_label(GTK_TOOL_BUTTON(it), description.c_str());

	return it;
}

string ToolButton::getToolDisplayName()
{
	XOJ_CHECK_TYPE(ToolButton);

	return this->description;
}

GtkWidget* ToolButton::getNewToolIcon()
{
	XOJ_CHECK_TYPE(ToolButton);

	return gtk_image_new_from_icon_name(iconName.c_str(), GTK_ICON_SIZE_SMALL_TOOLBAR);
}

void ToolButton::setActive(bool active)
{
	XOJ_CHECK_TYPE(ToolButton);

	if (GTK_IS_TOGGLE_TOOL_BUTTON(item))
	{
		gtk_toggle_tool_button_set_active(GTK_TOGGLE_TOOL_BUTTON(item), active);
	}
}
