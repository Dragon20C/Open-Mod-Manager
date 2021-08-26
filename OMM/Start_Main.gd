extends Node2D

var docs = OS.get_environment("HOME") + "/Documents"
var OMM_Folder = docs + "/Open Mod Manager"
onready var explorer = get_node("FileDialog")

func _ready():
	print(command_line("wine", "--version"))
	if check_all_files_exist():
		first_time()

func command_line(command : String, path : String):
	var output = []
	var exit_code = OS.execute(command, [path], true, output) 
	return output

func check_all_files_exist():
	var files_exist = false
	var directory = Directory.new()
	var config = ConfigFile.new()
	if !directory.dir_exists(docs + "/Open Mod Manager"):
		directory.make_dir(OMM_Folder)
		files_exist = true
		
	if config.load(OMM_Folder + "/OMM.ini") != OK:
		config.set_value("OMM", "Fallout4_Dir", "")
		config.save(OMM_Folder + "/OMM.ini")
		files_exist = true
		
	return files_exist

func first_time():
	get_node("Start_up").popup_centered(get_viewport_rect().size / 2)
	#print("first time setup")
	#explorer.popup_centered(get_viewport_rect().size / 2)

func set_ini_info(path : String):
	var config = ConfigFile.new()
	var err = config.load(OMM_Folder + "/OMM.ini")
	if err == OK:
		#if !config.has_section_key("OMM", "Fallout4_Dir"):
		if check_valid_folder(path):
			config.set_value("OMM", "Fallout4_Dir", path)
			config.save(OMM_Folder + "/OMM.ini")
		else:
			yield(get_tree().create_timer(0.1), "timeout")
			explorer.popup_centered(get_viewport_rect().size / 2)
			
		# Save the changes by overwriting the previous file
		

func _on_FileDialog_dir_selected(dir : String):
	set_ini_info(dir)

func check_valid_folder(path : String):
	var file = File.new()
	if file.file_exists(path + "/Fallout4.exe"):
		return true
	return false

