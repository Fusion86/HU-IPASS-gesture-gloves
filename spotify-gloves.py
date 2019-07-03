#!/usr/bin/env python3

import sys
import osascript

# Thanks to https://gist.github.com/NoobsArePeople2/5121597
# and https://coolaj86.com/articles/how-to-control-os-x-system-volume-with-applescript/
as_pause = 'tell application "Spotify"\nplaypause\nend tell'
as_volume_up = "set volume output volume (output volume of (get volume settings) + 5)"
as_volume_down = "set volume output volume (output volume of (get volume settings) - 5)"

for xline in sys.stdin:
    line = xline.rstrip()
    print(line)

    if "action:" in line:
        action = line.split(":")[1].strip()
        print("FOUND ACTION: " + action)
        if "toggle_play_pause" in action:
            osascript.run(as_pause)
        elif "volume_up" in action:
            osascript.run(as_volume_up)
        elif "volume_down" in action:
            osascript.run(as_volume_down)
