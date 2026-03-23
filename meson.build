fs = import('fs')
python = find_program('python3', 'python', required : false)

lua_names = ['lua-5.4','lua5.4','lua54','lua']
lua_dep = dependency(
    lua_names,
    required: true,
    not_found_message: 'Could not find lua, make sure it is installed, (lua 5.4)'
)

if python.found()
    message('Copying ExampleMod to mods')
    run_command(python, meson.current_source_dir() / 'copy.py', check: true)
else
    warning('python not found, skipping Copying ExampleMod')
endif

cml_sources = run_command(
    'sh', '-c',
    'find "' + meson.current_source_dir()
    + '" \\( -name "*.cpp" -o -name "*.c" \\)',
    check: true
).stdout().strip().split('\n')

cml_inc = include_directories('.', 'includes')

if fs.is_dir('/usr/include/lua5.4')
    message('Falling back to manual lua include')
    cml_inc = [cml_inc, include_directories('/usr/include/lua5.4')]
endif

cml_inc_dep = declare_dependency(
    include_directories: [cml_inc, include_directories('..')],
    dependencies: lua_dep
)

cml_dep = declare_dependency(
    sources: cml_sources,
    include_directories: [cml_inc, include_directories('..')],
    dependencies: lua_dep,
)