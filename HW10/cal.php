BUTTS
<HTML>
<BODY>
<FORM action="calendar.php" method="post">
Year: <input type="text" name="year">
<input type="submit">
</form>

<?php
if (array_key_exists("year",$_POST)) {
	process($_POST["year"]);
} else {
	process(date('Y')); // Process current year if year hasn't been set
}

function process($year)
{
	// Get current date object  
    $cdate = new DateTime('now');
    
    // Get date attributes` 
    $cyear = $cdate->format('Y');   // Current year
    $cmonth = $cdate->format('F');  // Current month
    $cdom = $cdate->format('j');    // Current day of the month 
    $cdw = $cdate->format('w');    // Current numeric day of the week 


	//$date->sub(new DateInterval('P' . $wd . 'D')); // ???
    //$date->sub(new DateInterval('P' . $dom . 'D')); // ???
    
    // Print out the DateTime Object 
	print_r($cdate);
    print "\n";

    // Get start of the year date object
    $sdate = new DateTime();          
    $sdate->setDate($year, 1, 1);  // January 1st for the specified year
    print_r($sdate); 
    print "\n"; 

    // Iterate through each month
    for ($i = 1; $i < 13; $i++) {
        // Get date info for the month 
        $yr = $sdate->format('Y');      // Year 
        $mon = $sdate->format('F');     // Month
        $dom = $sdate->format('j');     // Day of the month
        print "Original Start Point:\n";
        print_r($sdate);
        print "\n"; 
        $sdate->sub(new DateInterval('P' . $dom . 'D')); // Rewind by day of month to start month properly
        print "Rewind by day of month\n";
        print_r($sdate);
        print "\n";
        $wd = $sdate->format('w');      // After rewinding, get weekday 
        $sdate->sub(new DateInterval('P' . $wd . 'D')); 
        print "Rewind by weekday\n";
        print_r($sdate);
        print "\n"; 

        // Start table for that month
        print "<TABLE Border=1>\n"; // Top line
        print "<TR><TH COLSPAN=7>$mon $yr</TR>\n"; // Display month and year at top
        print "<TR><TH>Sun<TH>Mon<TH>Tue<TH>Wed<TH>Thu<TH>Fri<TH>Sat</TR>\n"; // Print Week

        // Fill up calendar 
        for ($j = 0; $j < 7*6; $j++) {
            $cday = $sdate->format('j');    // Get the current day of the month 
            if ($j % 7 == 0) {
                print "<TR>";               // Print new row
            } 
            if (($cday == $cdom) && ($mon == $cmonth) && ($yr == $cyear)) {
                print "<TD ALIGN=\"CENTER\" BGCOLOR=\"#FFFFAA\">$cday";     // Highlight current day
            } else if (($j < 7 && $cday > 7) || ($j > 28 && $cday < 22)) {
                print "<TD ALIGN=\"CENTER\" BGCOLOR=\"#808080\">$cday";     // Fade non-current month days 
            } else {
                print "<TD ALIGN=\"CENTER\">$cday";     // Print the current day 
            }
            if ($j % 7 == 6) {
                print "</TR>";                      // End row  
            }
            $sdate->add(new DateInterval('P1D'));   // Increment the date by one day
        }
        print "</TABLE>\n"; 
        $sdate->setDate($year, $i + 1, 1);          // Increment to the first of the next month
    }
    return; 
}
?>
</BODY>
</HTML>
<?php
