import subprocess
import zipfile
import os


def main():
    link_to_file = 'https://www.dropbox.com/s/kjodqw3tm7hc9vr/tests.zip'
    if not os.path.exists('tests'):
        os.mkdir('tests')
        os.chdir('tests')
        subprocess.Popen(['curl', '-L', '-o', 'tests.zip', link_to_file]).wait()
        zip_file = zipfile.ZipFile('tests.zip')
        zip_file.extractall()
        zip_file.close()
        os.remove('tests.zip')


if __name__ == '__main__':
    main()
