extends Control


# Declare member variables here. Examples:
# var a = 2
# var b = "text"


# Called when the node enters the scene tree for the first time.
func _ready():
	get_tree().connect("files_dropped",self,"dropped_files_path")

func dropped_files_path(dropped : PoolStringArray,screen : int):
	print(dropped)
