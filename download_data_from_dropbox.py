# import dropbox
import subprocess
import zipfile
import os


def main():
    # dbx = dropbox.Dropbox('sl.AumYW-Xjbjk4o3jaK6-mg8qTvDHxtlBBqrT6w9Tu4oUypFVFHKdXUMeOvdYgvp2KLpCT5msKhVUHOgaIfD4nb5zZtokQQ-ignk_qI8wHaV87tAfhXSjlYav5_-q3decJuDc8hu7j')
    # dbx.files_download_to_file(download_path="/tests", path='https://www.dropbox.com/s/kjodqw3tm7hc9vr/tests.zip?dl=0')
    # shared_link = dropbox.files.SharedLink(url='https://www.dropbox.com/sh/o49zz4eusg6z81h/AACQ_rM_PalSBgyJRYx0jXPta?dl=0')
    # listing = dbx.files_list_folder(path="", shared_link=shared_link)
    # tmp = dbx.files_download_zip_to_file(download_path="/tests", path='/sh/o49zz4eusg6z81h/AACQ_rM_PalSBgyJRYx0jXPta?dl=0')
    # tmp.close()
    # for entry in listing.entries[1:]:
    #     # print(entry)
    #     # metadata, res = dbx.files_download(entry.path_lower)
    #     metadata, res = dbx.files_download(path="/" + entry.name)
    #     # print(res.content)
    #     break
    if not os.path.exists('tests'):
        os.mkdir('tests')
        os.chdir('tests')
        subprocess.Popen(['curl', '-L', '-o', 'tests.zip', 'https://www.dropbox.com/s/kjodqw3tm7hc9vr/tests.zip']).wait()
        zip_file = zipfile.ZipFile('tests.zip')
        zip_file.extractall()
        zip_file.close()
        os.remove('tests.zip')


if __name__ == '__main__':
    main()
