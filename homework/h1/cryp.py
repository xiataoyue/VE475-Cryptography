# message = 'LWNSOZBNWVWBAYBNVBSQWVUOHWDIZWRBBNPBPOOUWRPAWXAWPBWZWMYPOBNPBBNWJPAWWRZSLWZQJBNVIAXAWPBSALIBNXWABPIRYRPOIWRPQOWAIENBVBNPBPUSREBNWVWPAWOIHWOIQWABJPRZBNWFYAVYIBSHNPFFIRWVVBNPBBSVWXYAWBNWVWAIENBVESDWARUWRBVPAWIRVBIBYBWZPUSREUWRZWAIDIREBHWIATYVBFSLWAVHASUBNWXSRVWRBSHBOTESDWARWZBNPBLNWWDWAPRJHSAUSHESDWARUWRBQWXSUWVZWVBAYXBIDWSHBNWVWWRZVIBIVBNVAIENBSHBNWFWSFOWBSPOBWASABSPQSOIVNIBPRZBSIRVBIBYBWRWLESDWARUWRBOPJIREIBVHSYRZPBISRSRVYXNFAIRXIFOOTPRZSAEPRIKIREIBVFSLWAVIRVYXNHSAUPVBSVWMJSVBOICWOJBSWHHWXBBNWIAVPHWBJPRZNPFFIRWW'
message = 'EVIRE'
for k in range(26):
    # output = chr((ord(message[0]) - 65 - k) % 26 + 97)
    output = ''
    for i in range(0, len(message)):
        output = output + chr((ord(message[i]) - 65 - k) % 26 + 97)
    print(output)
