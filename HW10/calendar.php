// Author: Sheaff (Modified by Nicholas LaJoie for ECE 331) 
// File: calendar.php
// Date: April 8, 2017
// Prints an entire calendar year based on year from user input, with current day highlighted,
// on a public webpage using a pi webserver 

<HTML>
<BODY>
<FORM action="php12.php" method="post">
Year: <input type="text" name="year">
<input type="submit">
</form>

<?php
if (array_key_exists("year",$_POST)) {
	process($_POST["year"]);
}

function process($year)
{
	$date=new DateTime('now');
	$nyear=$date->format('Y');
	if ($nyear>$year) {
		$d=$nyear-$year;
		$date->sub(new DateInterval('P' . $d . 'Y'));
	} else {
		$d=$year-$nyear;
		$date->add(new DateInterval('P' . $d . 'Y'));
	}
	$month=$date->format('F');
	$year=$date->format('Y');
	$dom=$date->format('j');
	$date->sub(new DateInterval('P' . $dom . 'D'));
	$wd=$date->format('w');
	$date->sub(new DateInterval('P' . $wd . 'D'));
	print_r($date);
	print "<TABLE Border=1>\n";
	print "<TR><TH COLSPAN=7>$month $year</TR>\n";
	print "<TR><TH>Sun<TH>Mon<TH>Tue<TH>Wed<TH>Thu<TH>Fri<TH>Sat<TH></TR>\n";
	for ($i=0;$i<7*5;$i++) {
		if ($i%7==0) {
			print "<TR>";
		}
		$cdom=$date->format('j');
		if ($dom==$cdom) {
			print "<TD ALIGN=\"CENTER\" BGCOLOR=\"#FFFFAA\">$cdom";
		} else {
			print "<TD ALIGN=\"CENTER\">$cdom";
		}
		if ($i%7==6) {
			print "</TR>";
			if ($date->format('F')!=$month) {
				break;
			}
		}
		$date->add(new DateInterval('P1D'));
	}
	print "</TABLE>\n";
	return;
}
?>
</BODY>
</HTML>
<?php
