export default function Card() {
  return (
    <div className="min-w-[7rem] min-h-[10rem] bg-zinc-600 rounded-lg border-2 border-white my-[1rem] cursor-pointer flex flex-col">
      <div className="info mt-auto bg-gradient-to-b from-gray-900">
        <h4 className="info-title">Info title</h4>
        <p className="info-date">23/04/23</p>
      </div>
    </div>
  )
}
