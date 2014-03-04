	var	x;
	var	y;
	
	if (document.getElementById)
	{
		if(navigator.appName.substring(0,3) == "Net")
			document.captureEvents(Event.MOUSEMOVE);
		document.onmousemove = Pos_Souris;
   }
	
	function Pos_Souris(e)
	{
		x = (navigator.appName.substring(0,3) == "Net") ? e.pageX : event.x+document.body.scrollLeft;
		y = (navigator.appName.substring(0,3) == "Net") ? e.pageY : event.y+document.body.scrollTop;
		document.getElementById("explain").innerHTML="Exemple : 25/04/1988";
		document.getElementById("explain").style.top=(y - 250)+"px";
		document.getElementById("explain").style.left=(x - 80)+"px";

	}
	
	function	explain(state)
	{
		var	x;
		var	y;
		
		if (state == "quit")
			opacity("explain", 100, 0, 100);
		if (state == "enter")
			opacity("explain", 0, 100, 100);
	}
