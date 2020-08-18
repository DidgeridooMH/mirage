project('mirage', 'cpp')

lib_src = ['src/Core/MApp.cpp',
           'src/Events/MClickEventHandler.cpp',
           'src/Events/MEventHandler.cpp',
           'src/Gui/MDrawable.cpp',
           'src/Gui/MText.cpp',
           'src/Gui/Windows/MWinWindow.cpp']

lib_inc = include_directories('src/')

libmirage = shared_library('mirage',
                           sources : lib_src,
                           include_directories : lib_inc)

executable('test-mirage',
           sources : ['test/main.cpp'],
           include_directories : include_directories(['test/', 'src/']),
           link_args: '-municode',
           link_with : libmirage)
