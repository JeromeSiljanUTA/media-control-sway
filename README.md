# media-control-sway
This program really only works with sway

What `media-control-sway` does is it polls `playerctl` and finds the current "players". It then checks what the focused window is and if the focused window is a "player", it will call `playerctl` on that window. If the focused window is not listed as a "player", it will call `playerctl` on `cmus` by default. 

This was just a script I wrote for myself. It has been tested with:
 - `mpv`
 - `cmus`
 - `firefox`

It'll probably work with `spotify`, but I don't use it and haven't tested it.

This project was thrown together quickly, so I expect that there's a lot of area to improve. If you have any suggestions/changed or have packaged this for a distro, just let me know. I'd love to help!

## Installing
```
git clone https://github.com/JeromeSiljanUTA/media-control-sway
cd media-control-sway
chmod 755 install.sh
sudo ./install.sh <user>
```

 - `<user>` is your username
 - The install script is not necessary, but helps get things set up

### Dependencies:
 - `sway`
 - `jq`
 - `playerctl`

## Uninstalling
` sudo ./remove.sh `

## Usage
`media-control-sway` is really just a glorified shell script wrapper for `playerctl`

It passes whatever argument you give it to `playerctl`, but specifies the player.

### Supported Arguments (taken from [Playerctl's README](https://github.com/altdesktop/playerctl))
|Command|Description|
|-|-|
| **`play`**                   | Command the player to play.                                                                            |
| **`pause`**                  | Command the player to pause                                                                            |
| **`play-pause`**             | Command the player to toggle between play/pause.                                                       |
| **`stop`**                   | Command the player to stop.                                                                            |
| **`next`**                   | Command the player to skip to the next track.                                                          |
| **`previous`**               | Command the player to skip to the previous track.                                                      |
| **`position [OFFSET][+/-]`** | Command the player to go to the position or seek forward or backward OFFSET in seconds.                |
| **`volume [LEVEL][+/-]`**    | Print or set the volume to LEVEL from 0.0 to 1.0.                                                      |
| **`status`**                 | Get the play status of the player. Either "Playing", "Paused", or "Stopped".                           |
| **`metadata [KEY...]`**      | Print the metadata for the current track. If KEY is passed, print only those values from the metadata. |
| **`open [URI]`**             | Command for the player to open a given URI. Can be either a file path or a remote URL.                 |
| **`loop [STATUS]`**          | Print or set the loop status. Either "None", "Track", or "Playlist".                                   |
| **`shuffle [STATUS]`**       | Print or set the shuffle status. Either "On", "Off".                                                   |

## To Do
 - [ ] Package media-control-sway for AUR
 - [ ] Make e-build for media-control-sway 
 - [ ] Use `wlr-foreign-toplevel` protocol
 - [ ] Create makefile
 - [ ] Add config file functionality that allows changes to default player
