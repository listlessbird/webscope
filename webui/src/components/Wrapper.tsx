export default function Wrapper({ children }: { children: React.ReactNode }) {
  return (
    <div
      className="
        wrapper 
        max-w-[48rem]
        mx-auto
        px-[1rem]
        lg:max-w-[60rem] px-0
        "
    >
      {children}
    </div>
  )
}
