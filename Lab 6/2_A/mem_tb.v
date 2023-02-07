module MCPU_RAMController_tb();

parameter WORD_SIZE=8;
parameter ADDR_WIDTH=8;
parameter RAM_SIZE=1<<ADDR_WIDTH;

reg we, re;
reg [WORD_SIZE-1:0] datawr;
reg [ADDR_WIDTH-1:0] addr;
reg [ADDR_WIDTH-1:0] instraddr;
wire [WORD_SIZE-1:0] datard;
wire [WORD_SIZE-1:0] instrrd;
reg [WORD_SIZE-1:0] mem[RAM_SIZE-1:0];

reg iscorrect;
reg [ADDR_WIDTH-1:0] addr_inputs;
reg [WORD_SIZE-1:0] datawr_inputs;

integer i;

MCPU_RAMController #(.WORD_SIZE(WORD_SIZE), .ADDR_WIDTH(ADDR_WIDTH), .RAM_SIZE(RAM_SIZE)) raminst(.we(we), .datawr(datawr), .re(re), .addr(addr), .datard(datard), .instraddr(instraddr), .instrrd(instrrd));

always #3
begin
  for(i=0;i<WORD_SIZE;i=i+1)
    begin
      datawr_inputs[i]=$random;
    end
  datawr=datawr_inputs;

  for(i=0;i<ADDR_WIDTH;i=i+1)
    begin
      addr_inputs[i]=$random;
    end
  addr=addr_inputs;
  instraddr=addr_inputs;
  
  if((datard == datawr_inputs) && (instrrd == datawr_inputs))
    iscorrect=1;
end

initial 
begin
  iscorrect=0;
  re=1;
  we=1;
end

endmodule