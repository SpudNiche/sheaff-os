<?php
function table($w, $h)
{
    print "<TABLE BORDER=1\n>";
    for ($i = 0; $i < ($w * $h); $i++) { 
        if ($i % $w == 0) { 
            print "<TR>";
        } else if ($i % $w == ($w - 1)) {
            print "</TR>";
        } else {
            print "<TD>$i";
        }
    }
    print "</TABLE>\n";
}
?>
