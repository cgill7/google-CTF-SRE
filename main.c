ulong main(void)

{
  int iVar1;
  uint uVar2;
  undefined auVar3 [16];
  undefined user_input [16];
  undefined4 local_28;
  undefined4 uStack36;
  undefined4 uStack32;
  undefined4 uStack28;
  
  printf("Flag: ");
  __isoc99_scanf(&DAT_0010200b,user_input);
  auVar3 = pshufb(user_input,SHUFFLE);
  auVar3 = CONCAT412(SUB164(auVar3 >> 0x60,0) + ADD32._12_4_,
                     CONCAT48(SUB164(auVar3 >> 0x40,0) + ADD32._8_4_,
                              CONCAT44(SUB164(auVar3 >> 0x20,0) + ADD32._4_4_,
                                       SUB164(auVar3,0) + ADD32._0_4_))) ^ XOR;
  local_28 = SUB164(auVar3,0);
  uStack36 = SUB164(auVar3 >> 0x20,0);
  uStack32 = SUB164(XOR >> 0x40,0);
  uStack28 = SUB164(XOR >> 0x60,0);
  iVar1 = strncmp(user_input,(char *)&local_28,0x10);
  if (iVar1 == 0) {
    uVar2 = strncmp((char *)&local_28,EXPECTED_PREFIX,4); // EXPECTED_PREFIX = "CTF{"
    if (uVar2 == 0) {
      puts("SUCCESS");
      goto LAB_00101112;
    }
  }
  uVar2 = 1;
  puts("FAILURE");
LAB_00101112:
  return (ulong)uVar2;
}
