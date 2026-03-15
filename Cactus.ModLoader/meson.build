modloader_sources = run_command(
    'sh', '-c',
    'find "' + meson.current_source_dir()
    + '" -maxdepth 3 \\( -name "*.cpp" -o -name "*.c" \\)',
    check: true
).stdout().strip().split('\n')

modloader_dep = declare_dependency(
    sources: modloader_sources,
    include_directories: include_directories('.', 'includes'),
    dependencies: lua_dep,
)