# ROSE Next Classic

ROSE Next classic was an attempt to develop a new version of ROSE Online based
on the existing irose code base. Many new developments were added at a
technical level with minor or no changes to the core gameplay. The biggest
change was porting the old ROSE code from MSSQL to Postgres.

This project has been discontinued but the work is released for others to
continue upon it if they wish. While there are some bugs, there are significant
enhancements over the original iROSE code.

Since this is likely the "biggest" release of any serious ROSE project in the
past several years, we hope that the community will appreciate our efforts.

Thanks to all that contributed.

## Quickstart

To get started quickly, consider using the existing Justfile. Available commands:

```
Available recipes:
    build config=CONFIG        # Build code projects
    build-all config=CONFIG    # Build all code and assets
    build-assets config=CONFIG # Build game assets
    cld key=""                 # Alias to start auto client in release
    client config=CONFIG       # Start the client
    client-auto config=CONFIG key="" # Start the client and auto-connect looking up the connection info in env
    clr key=""                 # Alias to start auto client in release
    dev-setup                  # Setup dev environment by linking to assets dir
    gameserver config=CONFIG   # Start gameserver
    gs config=CONFIG           # alias for `gameserver`
    loginserver config=CONFIG  # Start loginserver
    ls config=CONFIG           # alias for `loginserver`
    server-all config=CONFIG   # Start all servers
    worldserver config=CONFIG  # Start worldserver
    ws config=CONFIG           # alias for `worldserver`
```

- Install all the requirements (see (requirements)[#requirements])
- Setup the database, see (database)(#Database)
  - Squash the migrations
  - Create the database + tables
  - Create a new user
- Run `just build-all` to build all the requirements
- Run `just dev-setup` to setup a local dev environment
- Create `dev/server/settings.toml` (see `doc/server.toml.example` for a sample)
- Create a `.env` file in the main directory (see `doc/.env.example` for sample)
- Start client `just client`

## Build

### Requirements

- Rust 1.38+
- Visual studio 2019 Community or better
  - "Desktop development with C++" bundle is recommended
- PostgreSQL 12+
- Python 3+ (for scripts)
- Clang-format (for code formatting)
- Powershell core 7.0+
- (Optional) (just)[https://github.com/casey/just] 

### Build

The project consists of a mix of Rust code and C++ code. In order to build the project one must
first build all the Rust dependencies and then build the C++ projects. The Rust crates must be
built using the 32-bit mscv toolchain.

It's recommended to set the toolchain override for the entire `src/` directory using `rustup`. E.g.

```
cd src/
rustup override set stable-i686-pc-windows-msvc
rustup show
```

Once all the Rust dependendencies are built then all the thirdparty C++ dependencies must be built.
This can be done by compiling the `thirdparty.sln` solution. Finally we can compile the remaining
projects by compiling the `rose-next.sln` solution.

#### Rust

- Change into the src directory `cd src/`
- Install the 32-bit msvc toolchain `rustup toolchain install stable-i686-pc-windows-msvc`
- Set the toolchain override `rustup override set stable-i686-pc-windows-msvc`
- Build all project `cargo build` and `cargo build --release`

#### C++

- Open the `thirdparty.sln` solution and compile all projects
- Open the `rose-next.sln` solution and compile all the projects

> Note: Don't forget to build both configurations (debug/release)

## Client

### Assets

It is recommended to use your own assets but the original rose-next assets can
be downloaded from https://dl.flowan.io/public/rosenext/2021-03-09-assets.7z

The `client` requires assets to be baked before it can run. This can be
accomplished using the `pipeline` tool in conjunction with the `assets/bake.manifest`
file. However, this process can be automated be running the `scripts/build-assets.ps1` script.

### Debugging

The `client` project can be run from within Visual Studio to debug the executable. By default
it looks in the `dev/game/` directory for the runtime game assets

### Connecting to servers

Run `rosenext.exe --server <IP>` to connect to a server at a specific IP Address

#### Auto-connect

The client has an extra feature to automatically connect directly to the game
world. It requires that all the servers are running and that a character exists
and is known by name. E.g. usage:

```
rosenext.exe --server 127.0.0.1 --username user --password pass --auto-connect-server 1 --auto-connect-channel 1 --auto-connect-character MyChar
```

## Server

### Database

ROSE Next uses PostgreSQL for its database. It should work with any version
newer than Postgres 12.

To support the ever evolving schema changes of the production, the database
files are broken up into smaller "migration" files. Each migration is prefixed
with its version and a short descrptive name, e.g. "0001_rose-next". Each
migration script has an "up.sql" file used to create all the changes for the
migration and a "down.sql" to undo it. To setup the database each of these
migrations must be run in order by executing each "up.sql" script.

If setting up the databsae for the first time it is recommended to run the
`scripts/squash-migrations.ps1` script which will combine all the migrations
into one sql script which should make it easier to execute in the database.

- Install PostgreSQL 12+
- Create a new database, e.g. "rose-next"
- (Optional) Create a new user for the database
- Run `scripts/squash-migrations.ps1`
- Import `database/rose-next.sql` into the database using your database program
  - E.g. Using psql: `psql -f database/rose-next.sql`
- Update `server.toml` with the connection information for the database

### Data files

The servers require access to certain game data files. The server looks for these by default in a
folder called `data/` at the same level as the executable.

This is controlled in the `server.toml` configuration, e.g.

```toml
[worldserver]
data_dir = "C:\\dev\rose-next\server\data"

[gameserver]
data_dir = "C:\\dev\rose-next\server\data"
```

## Development

For development, it's recommended to create symlinks to the asset files used by
the client and folder. One can do this manually in their desired directories or
the script `scripts/dev-setup.ps1` can be used. This will create a directory
called `dev/` with the subdirectories `dev/client` and `dev/server`. These
directories should be set as the working directories when running the
client/server executables.

**NOTE**: This script assumes that the assets have already been baked at least
one. Refer to the docs for `scripts/build-assets.ps1`

- Run the `scripts/dev-setup.ps1` script
- Update the server configuration file (`dev/server/server.toml`) with your
  database settings.

See the (configuration)(#Configuration) section for further details on how to
setup the environment, such as add users, configuring the server and more.

## Configuration

### New user

Insert a row into `accounts`, the following fields are required:

- `email` - The user's email address
- `password` - SHA256 encoded and salted version of the user's password
- `salt` - The salt used to salt the password

The script `scripts/generate-password.py` can be used to convert a plain text
password to a sha256 password + salt.

### Config file

The servers have default values but can optionally read their values from a `server.toml` file in the
same directory as the executable.

Log levels can be controlled using the values 0-5. With 0 being the highest logging level and 5 being the lowest (no logs)

```
# Log levels
0 - Trace
1 - Debug
2 - Info
3 - Warn
4 - Error
5 - Off
```

```toml
[database]
ip = "127.0.0.1"
name = "SHO"
username = "seven"
password = "tpqmsgkcm"

[loginserver]
ip = "127.0.0.1"
port = 29000
server_port = 19000
password = "password"
log_level = 2
log_path = "C:\\rose\\logs\\loginserver.log"

[worldserver]
ip = "127.0.0.1"
port = 29100
server_port = 19001
world_name = "1Rose Next" # Prepend number to control ordering in world list
data_dir = "C:\\rose\data\\"
log_level = 2
log_path = "C:\\rose\\logs\\worldserver.log"

[gameserver]
ip = "127.0.0.1"
port = 29200
server_name = "Channel 1"
data_dir = "C:\\rose\\data\\"
log_level = 2
log_path = "C:\\rose\\logs\\worldserver.log"
```
