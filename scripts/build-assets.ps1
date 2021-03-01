param (
    [ValidateSet("release", "debug")]
    [string]$config = "release"
)


$rose_next_root = (Get-Item $PSScriptRoot).Parent

$tools_dir = (Join-Path $rose_next_root "bin" $config)
$asset_dir = (Join-Path $rose_next_root "assets/")
$pipeline = (Join-Path $tools_dir "pipeline.exe")

# Use the bundled texconv
$directxtex_ver = "2020.9.30"
$texconv = Join-Path $rose_next_root thirdparty directxtex-$directxtex_ver
$env:Path += ";$texConv"

# We always have to bake the assets regardless of configuration
$bake_manifest = (Join-Path $asset_dir "bake.manifest")
$bake_out = (Join-Path $rose_next_root "bin" "assets" "debug")

Write-Host "Baking assets from $asset_dir to $bake_out"
& $pipeline bake -c $bake_manifest $asset_dir $bake_out

# A release build is just the baked assets but packed
if ($config -eq "release") {
    $pack_manifest = (Join-Path $asset_dir "pack.manifest")
    $pack_out = (Join-Path $rose_next_root "bin" "assets" "release")

    Write-Host "Packing assets from $bake_out to $pack_out"
    & $pipeline pack -c $pack_manifest $bake_out $pack_out
}
