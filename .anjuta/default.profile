<?xml version="1.0"?>
<anjuta>
    <plugin name="Debugger" mandatory="no">
        <require group="Anjuta Plugin"
                 attribute="Location"
                 value="anjuta-debug-manager:DebugManagerPlugin"/>
    </plugin>
    <plugin name="Git" mandatory="no">
        <require group="Anjuta Plugin"
                 attribute="Location"
                 value="anjuta-git:Git"/>
    </plugin>
    <plugin name="GNU Debugger" mandatory="no">
        <require group="Anjuta Plugin"
                 attribute="Location"
                 value="anjuta-gdb:GdbPlugin"/>
    </plugin>
    <plugin name="Terminal" mandatory="no">
        <require group="Anjuta Plugin"
                 attribute="Location"
                 value="anjuta-terminal:TerminalPlugin"/>
    </plugin>
</anjuta>
