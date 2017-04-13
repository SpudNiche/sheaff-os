<!-- Author: Andy Sheaff, revised by Nicholas LaJoie to print entire calendar for a specified year -->
<!-- ECE 331 - HW10 - Problem 1 -->
<!-- Sources: php.net/manual/en/function.date.php and my pal Seth Raymond --> 

<HTML>
<BODY>
<FORM action="calendar.php" method="post">
Year: <input type="text" name="year">
<input type="submit">
</form>

<?php
// Get year to display calendar 
if (array_key_exists("year",$_POST)) {
	process($_POST["year"]);
} else {
	process(date('Y')); // Process current year if a year hasn't been set yet
}

// Process prints the appropriate calendar for a given year 
function process($year)
{
	// Get current date object and attributes
    $cdate = new DateTime('now');
    $cyear = $cdate->format('Y');   // Current year
    $cmonth = $cdate->format('F');  // Current month
    $cdom = $cdate->format('j');    // Current day of the month 
    $cdw = $cdate->format('w');     // Current numeric day of the week 
    
    // Get start of the year date object
    $sdate = new DateTime();          
    $sdate->setDate($year, 1, 1);  // January 1st for the specified year

    // Make large table that contains month tables
    print "<TABLE Border=1 Cellpadding=5 Cellspacing=5 BGCOLOR=\"F3F6F9\">\n";
    print "<TR><TH COLSPAN=4 BGCOLOR=\"#C3D4E5\">Nicholas LaJoie's Incredible Calendar</TR><TD>\n";

    // Iterate through each month
    for ($i = 1; $i < 13; $i++) {
        // Get date info for the current month 
        $yr = $sdate->format('Y');      // Year 
        $mon = $sdate->format('F');     // Month
        $dom = $sdate->format('j');     // Day of the month
        $wd = $sdate->format('w');      // Weekday (0 = Sun, 1 = Mon, etc.)  
        $sdate->sub(new DateInterval('P' . $wd . 'D')); // Rewind so the printed week starts on Sunday

        // Start table for the current month
        print "<TABLE Border=1>\n"; 
        print "<TR><TH COLSPAN=7 BGCOLOR=\"#C3D4E5\">$mon $yr</TR>\n"; // Display month and year at top
        print "<TR><TH>Sun<TH>Mon<TH>Tue<TH>Wed<TH>Thu<TH>Fri<TH>Sat</TR>\n"; // Print Week

        // Fill up calendar 
        for ($j = 0; $j < 7*6; $j++) {
            $cday = $sdate->format('j');    // Get the current day of the month 
            if ($j % 7 == 0) {
                if ($cday < 8 && $j > 8) {  // Bail if it starts to print an entire week from the next month
                    break;
                } else {
                    print "<TR>";           // Print new row
                }
            } 

            // Process the day
            if (($cday == $cdom) && ($mon == $cmonth) && ($yr == $cyear)) {
                print "<TD ALIGN=\"CENTER\" BGCOLOR=\"#B7CF8B\">$cday";     // Highlight current day
            } else if (($j < 7 && $cday > 7) || ($j > 28 && $cday < 22)) {
                print "<TD ALIGN=\"CENTER\" BGCOLOR=\"#838B91\">$cday";     // Fade non-current month days 
            } else {
                print "<TD ALIGN=\"CENTER\">$cday"; // Print the current day 
            }

            // Complete row if appropriate
            if ($j % 7 == 6) {
                print "</TR>";
            }

            // Increment the date by one day
            $sdate->add(new DateInterval('P1D'));  
        }
        // Complete table 
        print "</TABLE>\n"; 
        
        // Organize calendar with four months per row
        if ($i % 4 == 0) {
            print "</TD></TR><TR>\n";
        }
        if ($i != 12) {
           print "<TD>\n"; 
        }

        // Set date to the first of the next month
        $sdate->setDate($year, $i + 1, 1);       
    }
    // Complete entire calendar table and return
    print "</TABLE>\n";
    return; 
}
?>
</BODY>
</HTML>
<?php
