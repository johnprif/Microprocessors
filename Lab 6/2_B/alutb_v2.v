//6.1.b
module MCPU_Alutb_v2();

parameter CMD_SIZE=2;
parameter WORD_SIZE=8;

reg [CMD_SIZE-1:0] opcode;
reg [WORD_SIZE-1:0] r1;
reg [WORD_SIZE-1:0] r2;
wire [WORD_SIZE*2-1:0] out;
wire OVERFLOW;

reg [WORD_SIZE*2-1:0] golden_reference; //Memory box with correct numbers
reg iscorrect; 
reg CF; //Register for curry flag
MCPU_Alu #(.CMD_SIZE(CMD_SIZE), .WORD_SIZE(WORD_SIZE)) aluinst (opcode, r1, r2, out, OVERFLOW);

// Testbench code goes here
always
begin
  #3 r1=3;
  #3 r1=3;
  #3 r1=2;
  #3 r1=1;
end

always
begin
  #3 r2=3;
  #3 r2=3;
  #3 r2=2;
  #3 r2=1;
end

always #3 opcode[0] = $random;
always #3 opcode[1] = $random;

always #3
begin  
  case(opcode)
    0: golden_reference=r1&r2;
    1: golden_reference=r1|r2;
    2: golden_reference=r1^r2;
    default:  {CF, golden_reference}=r1+r2; 
  endcase
  #3
  //Check output every 3 ps 
  //if output is correct then iscorrect=1
  if(golden_reference[0]===out[0] && golden_reference[1]===out[1])
    begin
      iscorrect=1;
    end
  //if output is not correct then iscorrect=1
  if(golden_reference[0]!==out[0] && golden_reference[1]!==out[1])
    begin
      iscorrect=0;
    end
end

initial begin
  $display("@%0dns default is selected, opcode %b",$time,opcode);
end


endmodule


