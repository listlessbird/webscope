import { useContext } from "react"
import { WaveContext } from "../context"

export default function ChannelTable({ channelName }: { channelName: string }) {
  const { data } = useContext(WaveContext)

  console.log(data.datasets[0])

  return (
    <div className="container flex justify-center mt-3">
      <table
        className="max-w-[30rem] border-2 border-white self-center p-4 w-full
      "
      >
        <caption>{channelName}</caption>
        <tr className="text-center border header-row">
          <th>X</th>
          <th>Y</th>
        </tr>
        <tr>
          <td>X - val</td>
          <td>Y -Val</td>
        </tr>{" "}
        <tr>
          <td>X - val</td>
          <td>Y -Val</td>
        </tr>{" "}
        <tr>
          <td>X - val</td>
          <td>Y -Val</td>
        </tr>
      </table>
    </div>
  )
}
