import os
import subprocess
import sys
# 设置环境变量为 UTF-8
os.environ['LANG'] = 'en_US.UTF-8'
os.environ['LC_ALL'] = 'en_US.UTF-8'

# 设置标准输出和标准错误的编码为 UTF-8
sys.stdout.reconfigure(encoding='utf-8')
sys.stderr.reconfigure(encoding='utf-8')

# 创建 build 目录
if not os.path.exists('build'):
    os.makedirs('build')

# 进入 build 目录
os.chdir('build')

# 设置代码页为 UTF-8
# 注意：这里使用 shell=True 来确保 chcp 命令在 Windows 命令提示符中正确执行
subprocess.run('chcp 65001', shell=True, check=True)

# 使用 CMake 编译项目
subprocess.run(['cmake', '-G', 'MinGW Makefiles', '..'])
subprocess.run(['make'])

# 运行生成的可执行文件
subprocess.run(['./SmartCar'])
