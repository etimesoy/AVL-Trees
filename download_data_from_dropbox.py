from shutil import rmtree
import subprocess
import zipfile
import os


def main():
    link_to_zip_file = 'https://www.dropbox.com/s/ucvk77v43g7xhhz/tests.zip?dl=0'
    zip_file_name = 'tests.zip'
    tests_foler_name = 'tests'
    if os.path.exists(tests_foler_name):
        rmtree(tests_foler_name)
    os.mkdir(tests_foler_name)
    os.chdir(tests_foler_name)
    subprocess.Popen(['curl', '-L', '-o', zip_file_name, link_to_zip_file]).wait()
    zip_file = zipfile.ZipFile(zip_file_name)
    zip_file.extractall()
    zip_file.close()
    os.remove(zip_file_name)


if __name__ == '__main__':
    main()
