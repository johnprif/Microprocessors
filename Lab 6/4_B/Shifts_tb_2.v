//6.4.2
module Shifts_tb_2();

parameter CMD_SIZE=3;
parameter WORD_SIZE=2;

reg [CMD_SIZE-1:0] opcode;
reg [WORD_SIZE-1:0] r1;
reg [WORD_SIZE-1:0] r2;
wire [WORD_SIZE-1:0] out;
wire OVERFLOW;

reg iscorrect;
reg [WORD_SIZE-1:0] result;
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

always @(r1 or r2) 
begin
    case(opcode)
    4: result=r1<<r2; //LSL
    5: result=r1>>r2;  //LSR
    default: begin
             end
    endcase
    #3          
    if(result[0]===out[0] && result[1]===out[1])
    begin
      iscorrect=1;
    end
    if(result[0]!==out[0] || result[1]!==out[1])
    begin
      iscorrect=0;
    end
end    
initial 
begin
  opcode=4; //For LSL
  #200; //Wait for 200 ps and change the operation to LSR
  opcode=5; //For LSR
end  
  


endmodule

