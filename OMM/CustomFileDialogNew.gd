extends FileDialog



func set_info(title : String):
	window_title = title
	popup_centered(get_viewport_rect().size / 2)
	print("poped up")
	
func close():
	print("deleted")
	queue_free()

func _on_CustomFileDialog_popup_hide():
	close()
