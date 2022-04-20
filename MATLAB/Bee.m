
load 'ReferenceHRTF.mat' hrtfData sourcePosition   
 %%Loading sound and HRTF parameters
hrtfData = permute(double(hrtfData),[2,3,1]); 
sourcePosition = sourcePosition(:,[1,2]); 
  
fileReader = dsp.AudioFileReader('pszczolatest8khz.wav'); 
fileReader.SamplesPerFrame = 8000;  
 
audioIn = fileReader();   

%% Movement declaration
desiredAz = 0:1:360;  
desiredEl = ones(size(desiredAz))*30; 
desiredPosition = [desiredAz' desiredEl']; 

%% Head-Related Interpolation
interpolatedIR  = interpolateHRTF(hrtfData,sourcePosition,desiredPosition, ...
                                  "Algorithm","VBAP");
for i = 1:length(desiredAz)                                
    leftIR = squeeze(interpolatedIR(i,1,:))'; 
    rightIR = squeeze(interpolatedIR(i,2,:))';  
    leftFilter = dsp.FIRFilter('Numerator',leftIR); 
    rightFilter = dsp.FIRFilter('Numerator',rightIR); 
    leftChannel(:,i) = leftFilter(audioIn(:,1)); 
    rightChannel(:,i) = rightFilter(audioIn(:,2)); 
end  

%% Overlap using sinus function
mod1=(sin(pi/2:0.001:3/2*pi)+1)/2;
win2=mod1(1:131:3142)';
win = (1-win2);

for i = 1: 333 
nl((1:24)+24*(i-1))=leftChannel((1:24)+24*(i-1),i).*win2+ leftChannel((1:24)+24*(i-1),i+1) .* win;  
    nr((1:24)+24*(i-1))  =  rightChannel((1:24)+24*(i-1),i).*win2   + rightChannel((1:24)+24*(i-1),i+1) .* win;  
end     

%% Playing and saving new sound
soundOut = [nl; nr];  
sound(soundOut)
audiowrite('Bee-noise.wav',soundOut',8000);
