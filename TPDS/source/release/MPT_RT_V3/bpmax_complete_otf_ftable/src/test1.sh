while true
do
       #./../working/bpmax_complete_base/bpmax.verify-rand 7 196 48 3 24
       #./bpmax.verify-rand 7 196 48 3 24
       ./bpmax.verify-rand 5 17 8 1 8
       if [ $? -eq 0 ]
       then
          echo "New program matches base program                      [PASS]"
       else
          echo "[FAIL] WriteC program doesn't match base program         [FAIL]"
        exit 1
      fi
done
