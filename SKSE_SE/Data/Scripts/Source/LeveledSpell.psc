Scriptname LeveledSpell extends Form Hidden

; Adds the given count of the given form to the under the given level in this leveled list
Function AddForm(Form apForm, int aiLevel) native

; Removes all script added forms from this leveled list
Function Revert() native

; SKSE 64 additions built 2020-07-29 17:24:48.495000 UTC
int function GetChanceNone() native
Function SetChanceNone(int chance) native

int Function GetNumForms() native
Form Function GetNthForm(int n) native

int Function GetNthLevel(int n) native
Function SetNthLevel(int n, int level) native
