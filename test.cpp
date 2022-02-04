#include <stdio.h>
#include <windows.h>
#include <conio.h>

LPSTR lpMapping;


int main()
{
    BOOL    bEnd = FALSE;
    char    szNo[8];
    HANDLE    hMapRead;

    while (1)
    {

        printf("1. 공유 메모리 데이터 읽기\n");
        printf("0. 종료\n");
        printf("원하는 작업의 번호를 눌러주세요.");

        gets_s(szNo, sizeof(szNo));


        switch (szNo[0])
        {

        case '1':
            // 매핑 파일 열기
            hMapRead = OpenFileMapping(FILE_MAP_ALL_ACCESS,
                FALSE,
                TEXT("MemoryMapTest"));

            // 파일에 매핑하기
            lpMapping = (LPSTR)MapViewOfFile(hMapRead,
                FILE_MAP_ALL_ACCESS,
                0,
                0,
                0);


            if (lpMapping == NULL)
            {
                printf("읽기 실패\n");
                CloseHandle(hMapRead);
                return -1;
            }

            // 읽어들인 데이터 출력
            printf(lpMapping);
            if (UnmapViewOfFile(lpMapping) == 0)
            {
                printf("\n 읽기용 어드래스 매핑 실패\n");
            }
            else
            {
                printf("\n 읽기용 어드래스 매핑 성공\n");
                lpMapping = NULL;
            }

            CloseHandle(hMapRead);
            break;

        case '0':
            bEnd = TRUE;
            break;

        default:
            printf("번호가 잘못됨 \n");
            break;

        }

        if (bEnd)
            break;

    }

    return 0;
}