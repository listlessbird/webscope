import { WaveContextProvider } from "../context";
import PlotView from '../components/PlotView';
import ChannelTable from "../components/ChannelTable";

export default function Main() {
  return (
    <main className="pr-[1rem] pl-[1rem]">
      <WaveContextProvider>
        <PlotView />
        <ChannelTable channelName="channel 1" />
      </WaveContextProvider>
    </main>
  )
}
