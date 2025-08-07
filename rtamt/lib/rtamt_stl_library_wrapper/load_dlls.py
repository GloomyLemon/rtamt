
import os
import ctypes
import subprocess

def load_dll(path_to_dll, loaded=set()):
    """
    Checks if the DLL file exists, finds and prints its dependencies using dumpbin (Windows),
    loads the dependencies recursively from directories listed in the system PATH,
    and loads the DLL using ctypes.

    Parameters:
        path_to_dll (str): The full path to the DLL file.
        loaded (set): Set of already loaded DLL paths to avoid reloading.

    Returns:
        ctypes.CDLL object if successful, None otherwise.
    """
    if not os.path.isfile(path_to_dll):
        print(f"Error: DLL file not found at '{path_to_dll}'")
        return None

    abs_path = os.path.abspath(path_to_dll)
    # if abs_path in loaded:
    #     print(f"Already loaded: {abs_path}")
    #     return None

    # print(f"Checking dependencies for DLL: {abs_path}")
    dependencies = []
    try:
        result = subprocess.run(
            ['dumpbin', '/DEPENDENTS', abs_path],
            capture_output=True,
            text=True,
            shell=True
        )
        if result.returncode == 0:
            lines = result.stdout.splitlines()
            start = False
            for line in lines:
                if "Image has the following dependencies:" in line:
                    start = True
                    continue
                if start and ".dll" in line:
                    line = line.strip()
                    dependencies.append(line)
            # print("Dependencies found:")
            # for dep in dependencies:
            #     print(f"  {dep}")
        else:
            print("Failed to retrieve dependencies. Make sure 'dumpbin' is available in your PATH.")
    except Exception as e:
        print(f"Error checking dependencies: {e}")

    try:
        dll = ctypes.CDLL(abs_path)
        loaded.add(abs_path)
        # print(f"Successfully loaded DLL from '{abs_path}'")
        return dll
    except:
        # print("Could not load DLL yet.")
        # Attempt to load dependencies recursively from PATH
        path_dirs = os.environ.get("PATH", "").split(os.pathsep)
        for dep in dependencies:
            for dir_path in path_dirs:
                dep_path = os.path.join(dir_path, dep)
                if os.path.isfile(dep_path):
                    load_dll(dep_path, loaded)
                    break
            else:
                print(f"Warning: Dependency '{dep}' not found in system PATH.")
    # Load the main DLL
    try:
        dll = ctypes.CDLL(abs_path)
        loaded.add(abs_path)
        # print(f"Successfully loaded DLL from '{abs_path}'")
        return dll
    except OSError as e:
        print(f"Failed to load DLL: {e}")
        return None

def init_dlls():
    load_dll(os.path.join(os.path.dirname(os.path.abspath(__file__)), "stl_abs_node.pyd"))