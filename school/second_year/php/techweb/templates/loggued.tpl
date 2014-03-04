<div><span class="gris_12">Bonjour <span class="vert_12"><b>{$login}</b></span>,<br /><br /></span>
<span class="gris_10">
Projets en cours: <span class="vert_10"><b>0</b></span><br />
Projets acheves: <span class="vert_10"><b>0</b></span><br />

{if $invitations != 0}
[<a href="index.php?view=invitations">Vous avez {$invitations} invitation(s)</a>]<br />
{else}
[<a href="index.php?view=invitations">Aucune invitation</a>]<br />
{/if}
[<a href="includes/include_deloggue.php">deconnection</a>]<br />
</span>
</div>