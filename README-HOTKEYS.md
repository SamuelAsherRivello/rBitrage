# Raylib C++ Project Template

### Optional: Add keyboard shortcut

1. [Setup Environment & Build Project](README.md) first
1. **Open Command Palette**  
   Press `Ctrl + Shift + P` to open the Command Palette.
1. **Access Keybindings Configuration**  
   Type `Preferences: Open Keyboard Shortcuts (JSON)` in the Command Palette and select it.
1. **Edit Keybindings JSON**  
   The `keybindings.json` file will open. Add the following code snippet to bind `Ctrl + Alt + Shift + A` (or whatever you like) to your custom terminal command:
   ```json
   {
      "key": "ctrl+shift+alt+a",
      "command": "workbench.action.tasks.runTask",
      "args": "Build and Execute"
   },
   ```
1. **Save the Changes**  
   Save the `keybindings.json` file.
1. **Test the Shortcut**  
   Press `Ctrl + Alt + Shift + A` (or whatever you like) in VS Code. The command will execute in the terminal.
