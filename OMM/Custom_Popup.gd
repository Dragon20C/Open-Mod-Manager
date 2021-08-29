extends AcceptDialog


func set_info(text : String, title : String):
	dialog_text = text
	window_title = title
	popup_centered(get_viewport_rect().size / 2)
	print("poped up")
	
func close():
	print("deleted")
	queue_free()



func _on_Custom_Popup_popup_hide():
	close()
