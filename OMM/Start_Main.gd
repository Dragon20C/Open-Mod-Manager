extends Node2D

var docs = OS.get_environment("HOME") + "/Documents"
var OMM_Folder = docs + "/Open Mod Manager"
onready var explorer = get_node("FileDialog")

var mod_folder = false

func _ready():
	print(command_line("wine", "--version"))
	if check_all_files_exist():
		first_time()

func command_line(command : String, path : String):
	var output = []
	OS.execute(command, [path], true, output) 
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
		
	if !config.has_section_key("OMM", "Mod_Folder_exist"):
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
			if !mod_folder or !config.has_section_key("OMM", "Mod_Folder_exist"):
				get_node("Mod_start_up").popup_centered(get_viewport_rect().size / 2)
		else:
			yield(get_tree().create_timer(0.1), "timeout")
			explorer.popup_centered(get_viewport_rect().size / 2)
			#if !mod_folder or !config.has_section_key("OMM", "Mod_Folder_exist"):
			#	get_node("Mod_start_up").popup_centered(get_viewport_rect().size / 2)
		# Save the changes by overwriting the previous file
		

func _on_FileDialog_dir_selected(dir : String):
	set_ini_info(dir)
	print("opened up ini")

func check_valid_folder(path : String):
	var file = File.new()
	if file.file_exists(path + "/Fallout4.exe"):
		return true
	return false

func create_mod_folder(path : String):
	var config = ConfigFile.new()
	config.load(OMM_Folder + "/OMM.ini")
	mod_folder = true
	config.set_value("OMM", "Mod_Folder_exist", mod_folder)
	config.set_value("OMM", "Mod_Folder_path", path)
	config.save(OMM_Folder + "/OMM.ini")
	print("making mod folder")

func _on_ModFolder_dir_selected(dir):
	print("mod folder")
	create_mod_folder(dir)
	
func _on_Mod_start_up_confirmed():
	get_node("ModFolder").popup_centered(get_viewport_rect().size / 2)
	print("start mod")

func list_files_in_directory(path):
	var files = []
	var dir = Directory.new()
	dir.open(path)
	dir.list_dir_begin()

	while true:
		var file = dir.get_next()
		if file == "":
			break
		elif not file.begins_with("."):
			files.append(file)

	dir.list_dir_end()

	return files

func install_F4SE():
	var fallout4_dir : String = ""
	var config = ConfigFile.new()
	var data_config = ConfigFile.new()
	var directory = Directory.new()
	var file = File.new()
	var err = config.load(OMM_Folder + "/OMM.ini")
	if err == OK:
		fallout4_dir = config.get_value("OMM","Fallout4_Dir")
		var F4SE_Files = get_dir_contents("res://F4SE")
		var F4SE_File_names = list_files_in_directory("res://F4SE")
		if !directory.dir_exists(fallout4_dir +"/Launcher_backup"):
			directory.make_dir(fallout4_dir +"/Launcher_backup")
			
		if !file.file_exists(fallout4_dir +"/Launcher_backup/Fallout4Launcher.exe"):
			directory.copy(fallout4_dir + "/Fallout4Launcher.exe",fallout4_dir +"/Launcher_backup/Fallout4Launcher.exe")
			directory.rename(fallout4_dir + "/Fallout4Launcher.exe",fallout4_dir + "/Fallout4Launcher.exe.backup")
		
		if !directory.file_exists(fallout4_dir +"/"+ F4SE_File_names[0]):
			for x in F4SE_Files.size():
				print(fallout4_dir +"/"+ F4SE_File_names[x])
				directory.copy(F4SE_Files[x],fallout4_dir +"/"+ F4SE_File_names[x])
				
		if file.file_exists(fallout4_dir + "/f4se_loader.exe"): #To make F4SE to launch on steam
			directory.rename(fallout4_dir + "/f4se_loader.exe",fallout4_dir +"/Fallout4Launcher.exe") 
		if !directory.dir_exists(fallout4_dir + "/Data/F4SE"): # Creates F4SE Folder
				directory.make_dir(fallout4_dir + "/Data/F4SE")
				if data_config.load(fallout4_dir + "/Data/F4SE/f4se.ini") != OK:
					data_config.set_value("Loader", "RuntimeName", "Fallout4.exe")
					data_config.save(fallout4_dir + "/Data/F4SE/f4se.ini")
					directory.make_dir(fallout4_dir + "/Data/F4SE/Plugins")
					directory.copy("res://achievements_DLL/achievements.dll",fallout4_dir + "/Data/F4SE/Plugins/achievements.dll")
		
func _on_Button_pressed():
	install_F4SE()

func get_dir_contents(rootPath: String) -> Array:
	var files = []
	var dir = Directory.new()

	if dir.open(rootPath) == OK:
		dir.list_dir_begin(true, false)
		_add_dir_contents(dir, files)
	else:
		push_error("An error occurred when trying to access the path.")

	return files

func _add_dir_contents(dir: Directory, files: Array):
	var file_name = dir.get_next()

	while (file_name != ""):
		var path = dir.get_current_dir() + "/" + file_name
		files.append(path)

		file_name = dir.get_next()

	dir.list_dir_end()


func _on_StartGameButton_pressed():
	#command_line()
	pass
