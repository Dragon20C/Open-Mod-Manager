extends Node
class_name Storage

var docs = OS.get_environment("HOME") + "/Documents"
var OMM_Folder = docs + "/Open Mod Manager"
var skyrim = "Skyrim_SE"
var fallout4 = "Fallout_4"


func command_line(command : String, path : String):
	var output = []
	OS.execute(command, [path], true, output) 
	return output

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
		return true
	return false

func uninstall_F4SE():
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
			
		if file.file_exists(fallout4_dir +"/Launcher_backup/Fallout4Launcher.exe"):
			directory.copy(fallout4_dir +"/Launcher_backup/Fallout4Launcher.exe",fallout4_dir + "/Fallout4Launcher.exe")
			directory.remove(fallout4_dir +"/Launcher_backup/Fallout4Launcher.exe")
			#directory.rename(fallout4_dir + "/Fallout4Launcher.exe",fallout4_dir + "/Fallout4Launcher.exe.backup")
		
		if directory.file_exists(fallout4_dir +"/"+ F4SE_File_names[0]):
			for x in F4SE_Files.size():
				print(fallout4_dir +"/"+ F4SE_File_names[x])
				directory.remove(fallout4_dir +"/"+ F4SE_File_names[x])
				#directory.copy(F4SE_Files[x],fallout4_dir +"/"+ F4SE_File_names[x])
				
		#if file.file_exists(fallout4_dir + "/f4se_loader.exe"): #To make F4SE to launch on steam
		#	directory.rename(fallout4_dir + "/f4se_loader.exe",fallout4_dir +"/Fallout4Launcher.exe") 
		if directory.dir_exists(fallout4_dir + "/Data/F4SE"): # Creates F4SE Folder
			directory.remove(fallout4_dir + "/Data/F4SE/Plugins/achievements.dll")
			directory.remove(fallout4_dir + "/Data/F4SE/Plugins")
			directory.remove(fallout4_dir + "/Data/F4SE/f4se.ini")
			directory.remove(fallout4_dir + "/Data/F4SE")
		return true
	return false
	
func create_mod_folder(path : String):
	var mod_folder = false
	var config = ConfigFile.new()
	config.load(OMM_Folder + "/OMM.ini")
	mod_folder = true
	config.set_value("OMM", "Mod_Folder_exist", mod_folder)
	config.set_value("OMM", "Mod_Folder_path", path)
	config.save(OMM_Folder + "/OMM.ini")
	print("making mod folder")
