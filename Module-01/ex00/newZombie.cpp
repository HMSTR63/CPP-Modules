#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
    Zombie *new_Zombie = new Zombie(name);
    if (!new_Zombie)
        return NULL;
    return new_Zombie;
}

//
// //<BS==============================================================================
// vim.provider:                                                             7 ⚠️
//
// Clipboard (optional) ~
// - ⚠️ WARNING No clipboard tool found. Clipboard registers (`"+` and `"*`) will not work.
//   - ADVICE:
//     - :help |clipboard|
//
// Node.js provider (optional) ~
// - Node.js: v22.21.1
//
// - ⚠️ WARNING Missing "neovim" npm (or yarn, pnpm) package.
//   - ADVICE:
//     - Run in shell: npm install -g neovim
//     - Run in shell (if you use yarn): yarn global add neovim
//     - Run in shell (if you use pnpm): pnpm install -g neovim
//     - You may disable this provider (and warning) by adding `let g:loaded_node_provider = 0` to your init.vim
//
// Perl provider (optional) ~
// - ⚠️ WARNING "Neovim::Ext" cpan module is not installed
//   - ADVICE:
//     - See :help |provider-perl| for more information.
//     - You can disable this provider (and warning) by adding `let g:loaded_perl_provider = 0` to your init.vim
// - ⚠️ WARNING No usable perl executable found
//
// Python 3 provider (optional) ~
// - ⚠️ WARNING No Python executable found that can `import neovim`. Using the first available executable for diagnostics.
// - ⚠️ WARNING Could not load Python :
//   /usr/bin/python3 does not have the "neovim" module.
//   python3.13 not found in search path or not executable.
//   /usr/bin/python3.12 does not have the "neovim" module.
//   python3.11 not found in search path or not executable.
//   python3.10 not found in search path or not executable.
//   python3.9 not found in search path or not executable.
//   python not found in search path or not executable.
//   - ADVICE:
//     - See :help |provider-python| for more information.
//     - You can disable this provider (and warning) by adding `let g:loaded_python3_provider = 0` to your init.vim
// - Executable: Not found
//
// Python virtualenv ~
// - ✅ OK no $VIRTUAL_ENV
//
// Ruby provider (optional) ~
// - ⚠️ WARNING `ruby` and `gem` must be in $PATH.
//   - ADVICE:
//     - Install Ruby and verify that `ruby` and `gem` commands work.
// >
