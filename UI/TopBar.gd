extends Control

onready var custom_popup = preload("res://OMM/Custom_Popup.tscn")

onready var F4SE = get_node("HBoxContainer/F4SE Options")
var popup

func _ready():
	popup = F4SE.get_popup()
	popup.connect("id_pressed", self, "_on_item_pressed")

func _on_item_pressed(ID):
	match_id(str(ID))

func match_id(ID : String):
	match ID:
		"0":
			if StorageClass.install_F4SE():
				var instance = custom_popup.instance()
				add_child(instance)
				var text = "Fallout 4 script extender succesfully installed, start your game and a console should pop up"
				instance.set_info(text,"Installing F4SE")
			else:
				var instance = custom_popup.instance()
				add_child(instance)
				var text = "Failed to install fallout 4 script extender, please report this issue on github"
				instance.set_info(text,"Installing F4SE")
		"1":
			if StorageClass.uninstall_F4SE():
				var instance = custom_popup.instance()
				add_child(instance)
				var text = "Fallout 4 script extender succesfully uninstalled, Your game should be default now"
				instance.set_info(text,"Uninstalling F4SE")
			else:
				var instance = custom_popup.instance()
				add_child(instance)
				var text = "Failed to uninstall fallout 4 script extender, please report this issue on github"
				instance.set_info(text,"Uninstalling F4SE")
				
func _on_About_pressed():
	var about_text = "This is a cool program made by me (Dragon20C), I have been playing fallout 4 and I noticed if I wanted to mod I would need to install lutris and there was a good chance it wouldnt work or use outdated proton versions, so I decided to make a mod manager"
	var instance = custom_popup.instance()
	add_child(instance)
	instance.set_info(about_text,"About me!")
