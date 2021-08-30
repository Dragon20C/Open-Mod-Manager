extends Control

onready var custom_popup = preload("res://OMM/Custom_Popup.tscn")
onready var custom_filedialog = preload("res://OMM/CustomFileDialogNew.tscn")

onready var F4SE = get_node("HBoxContainer/F4SE Options")
onready var MOD = get_node("HBoxContainer/Mods Settings")
var popup_F4SE
var popup_MOD

func _ready():
	popup_F4SE = F4SE.get_popup()
	popup_F4SE.connect("id_pressed", self, "_on_item_pressed")
	popup_MOD = MOD.get_popup()
	popup_MOD.connect("id_pressed",self,"_on_mod_item_pressed")

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
				instance.connect("confirmed",self,"printing")
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

func _on_mod_item_pressed(ID):
	match_mod_item(str(ID))
	
func match_mod_item(ID : String):
	match ID:
		"0":
			var instance = custom_popup.instance()
			add_child(instance)
			var text = "Open mod manager is now going to ask you to choose a folder to store all your mods, if changing to a new directory please move them manually!"
			instance.set_info(text,"Creating a mod folder")
			instance.connect("confirmed",self,"create_file_dialog_for_mods_folder")

func create_file_dialog_for_mods_folder():
	var instance = custom_filedialog.instance()
	add_child(instance)
	instance.set_info("create or select a mod folder")
	instance.connect("dir_selected",self,"create_mod_folder")
	
func create_mod_folder(dir):
	StorageClass.create_mod_folder(dir)
	var instance = custom_popup.instance()
	var file = ConfigFile.new()
	file.load(StorageClass.OMM_Folder + "/OMM.ini")
	var path = file.get_value("OMM","Mod_Folder_path")
	add_child(instance)
	instance.set_info("( " + path +" )" + " Has been selected as the path to storing all your fallout 4 mods","A Mod folder has been selected")

func _on_Install_a_mod_pressed():
	pass # Replace with function body.

func printing():
	print("test stuff out yo!")
