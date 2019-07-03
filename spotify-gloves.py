#!/usr/bin/env python3

import sys
import osascript

# Thanks to https://gist.github.com/NoobsArePeople2/5121597
# and https://coolaj86.com/articles/how-to-control-os-x-system-volume-with-applescript/
as_pause = 'tell application "Spotify"\nplaypause\nend tell'
as_volume_up = "set volume output volume (output volume of (get volume settings) + 5)"
as_volume_down = "set volume output volume (output volume of (get volume settings) - 5)"
as_next = 'tell application "Spotify"\nnext track\nend tell'
as_prev = 'tell application "Spotify"\nprevious track\nend tell'

# Ignore any errors we might encounter
sys.stdin.reconfigure(encoding="utf-8", errors="ignore")

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
        elif "next" in action:
            osascript.run(as_next)
        elif "prev" in action:
            osascript.run(as_prev)
