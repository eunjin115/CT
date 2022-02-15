void SendFile(std::string path, Data*& shared_data)
{
    std::ifstream fin;

    if (WaitForSingleObject(hMutex, INFINITE) == WAIT_OBJECT_0) //lock 걸렸다면 종료까지 대기
    {
        fin.open(path, std::ios::binary);
        fin.seekg(0, std::ios::end);

        shared_data->file_size = fin.tellg();
        fin.seekg(0, std::ios::beg);

        fin.read(shared_data->buffer, shared_data->file_size);
        fin.close();

        std::cout << "File Sending is done. \n\n";

        ReleaseMutex(hMutex); //unlock 
    }
}

void RecvFile(std::string path, Data*& shared_data)
{
    if (shared_data->file_size != 0)
    {
        std::ofstream fout;
        fout.open(path, std::ios::binary);
        fout.write(shared_data->buffer, shared_data->file_size);
        std::cout << "Read Done \n\n";
    }
    else
    {
        std::cout << "buffer is empty! \n";
        return;
    }
}