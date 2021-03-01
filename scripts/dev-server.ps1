param (
    [ValidateSet("release", "debug")]
    [string]$config = "release",

    [ValidateSet("loginserver", "worldserver", "gameserver")]
    [string]$server
)

$rose_next_root = (Get-Item $PSScriptRoot).Parent
$server_dir = (Join-Path $rose_next_root "dev" "server")
$server_settings = (Join-Path $server_dir "server.toml")
$server_exe = (Join-Path $rose_next_root "bin" $config "sho_$server")

Start-Process -FilePath $server_exe -ArgumentList "--config", "$server_settings"
