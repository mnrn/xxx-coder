BEGIN { RS="" }
{
    pat = sprintf("^[0-9]{%d}-[0-9]{%d}$", $1, $2)
    print ($3~pat)?"Yes":"No"
}
