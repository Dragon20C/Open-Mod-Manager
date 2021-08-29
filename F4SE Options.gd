extends MenuButton



var popup

func _ready():
	popup = get_popup()
	popup.connect("id_pressed", self, "_on_item_pressed")

func _on_item_pressed(ID):
	print(popup.get_item_text(ID), " pressed")
