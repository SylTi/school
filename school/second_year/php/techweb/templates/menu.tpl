<div id="menu">
<div class="men_a"><a href="./">Index</a></div>
<div class="men_a"><a href="index.php?view=doc">doc</a></div>
<div class="men_a"><a href="forum/">forum</a></div>
{if $login}
    <div style="width: 100px; float: left;">&nbsp;</div>
    <div class="men_a"><a class="vert_10" href="index.php?view=profil">Profil</a></div>
    <div class="men_a"><a class="vert_10" href="index.php?view=projets">Projets</a></div>
    <div class="men_a"><a class="vert_10" href="index.php?view=invitations">Invitations</a></div>
    <div class="men_a"><a class="vert_10" href="index.php?view=planning">Planning / Gant</a></div>
    <div class="men_a"><a class="vert_10" href="index.php?view=agenda">Agenda / Rdv</a></div>
    {if $rank == "1"}
    <div class="men_a"><a class="vert_10" href="index.php?view=admin">Admin</a></div>
    {/if}
    <div class="men_a"><a class="vert_10" href="includes/include_deloggue.php">Deconnection</a></div>
{/if}
</div>
