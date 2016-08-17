//=======================================================================
// Copyright Baptiste Wicht 2013-2016.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//=======================================================================

#include <tlib/file.hpp>
#include <tlib/system.hpp>
#include <tlib/errors.hpp>
#include <tlib/print.hpp>
#include <tlib/flags.hpp>

int main(int argc, char* argv[]){
    if(argc == 1){
        print_line("Usage: writer file_path");
        return 1;
    }

    auto fd = open(argv[1], std::OPEN_CREATE);

    if(fd.valid()){
        auto truncate_result = truncate(*fd, 12);

        if(truncate_result.valid()){
            auto s = "0123456789AB";

            auto write_result = write(*fd, s, 12, 0);

            if(write_result.valid()){
                //TODO
            } else {
                printf("writer: error: %s\n", std::error_message(write_result.error()));
            }
        } else {
            printf("writer: error: %s\n", std::error_message(truncate_result.error()));
        }

        close(*fd);
    } else {
        printf("writer: error: %s\n", std::error_message(fd.error()));
    }

    return 0;
}
