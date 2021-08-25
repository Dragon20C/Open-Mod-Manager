extends AcceptDialog

func _on_Popup_confirmed():
	get_parent().explorer.popup_centered(get_viewport_rect().size / 2)
